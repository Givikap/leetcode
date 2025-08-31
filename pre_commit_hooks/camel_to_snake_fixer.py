import argparse
import re
from collections.abc import Sequence
from pathlib import Path

# Regex to match camelCase identifiers while ignoring class names, and function definitions and calls.
#
# Explanation:
#   (?<!class\s)                -> Skip matches immediately following 'class ' (class names)
#   (?<!def\s)                  -> Skip matches immediately following 'def ' (function names)
#   \b([a-z]+[A-Z][a-zA-Z]*)\b  -> Match camelCase identifier
#   (?!\s*\()                   -> Skip matches immediately followed by '(' (function calls)
CAMEL_CASE_REGEX = re.compile(
    r"(?<!class\s)(?<!def\s)(\b[a-z]+[A-Z][a-zA-Z]*\b)\b(?!\s*\()"
)


def camel_to_snake(name: str) -> str:
    s1 = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", name)
    return s1.lower()


def fix_file(path: Path) -> int:
    content = path.read_text()
    new_content = CAMEL_CASE_REGEX.sub(lambda m: camel_to_snake(m.group()), content)

    if new_content != content:
        path.write_text(new_content)
        return 1

    return 0


def main(argv: Sequence[str] | None = None) -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("filenames", nargs="*", help="Filenames to fix.")
    args = parser.parse_args(argv)

    retval = 0

    for filename in args.filenames:
        retval_for_file = fix_file(Path(filename))

        if retval_for_file:
            print(f"Fixing {filename}")

        retval = retval_for_file

    return retval


if __name__ == "__main__":
    SystemExit(main())
