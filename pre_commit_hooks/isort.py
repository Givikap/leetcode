from isort.hooks import git_hook

if __name__ == "__main__":
    SystemExit(git_hook(strict=True, modify=True, lazy=True))
