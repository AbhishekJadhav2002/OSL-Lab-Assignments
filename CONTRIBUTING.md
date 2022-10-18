# Contributing Guidelines 👨‍💻
## 👨‍💻 Prerequisite Skills to Contribute

### Contribute in public/Profile

- C
- C++
- Bash
- Linux
- Operating Systems

### Contribute in Documents

- [Markdown](https://www.markdownguide.org/basic-syntax/)

## ⭐ HOW TO MAKE A PULL REQUEST:

**1.** Start by making a Fork of the [**OSL-Lab-Assignments**](https://github.com/AbhishekJadhav2002/OSL-Lab-Assignments) repository. Click on the Fork symbol at the top right corner.

**2.** Clone your new fork of the repository in the terminal/CLI on your computer with the following command:

```bash
git clone https://github.com/<your-github-username>/OSL-Lab-Assignments
```

**3.** Navigate to the newly created project directory:

```bash
cd OSL-Lab-Assignments
```

**4.** Set upstream command:

```bash
git remote add upstream https://github.com/AbhishekJadhav2002/OSL-Lab-Assignments.git
```

**5.** Create a new branch:

```bash
git checkout -b YourBranchName
```

**6.** Sync your fork or your local repository with the origin repository:

- In your forked repository, click on "Fetch upstream"
- Click "Fetch and merge"

### Alternatively, Git CLI way to Sync forked repository with origin repository:

```bash
git fetch upstream
```

```bash
git merge upstream/main
```

### [Github Docs](https://docs.github.com/en/github/collaborating-with-pull-requests/addressing-merge-conflicts/resolving-a-merge-conflict-on-github) for Syncing

**7.** Make your changes to the source code.

**8.** Stage your changes and commit:

⚠️ **Make sure** not to run the commands `git add .` or `git add *`. Instead, stage your changes for each file/folder

```bash
git add public
```

```bash
git commit -m "<your_commit_message>"
```

**9.** Push your local commits to the remote repository:

```bash
git push origin YourBranchName
```

**10.** Create a [Pull Request](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request)!

**11.** **Congratulations!** You've made your first contribution to [**OSL-Lab-Assignments**](https://github.com/AbhishekJadhav2002/OSL-Lab-Assignments/graphs/contributors)! 🙌🏼

---
## Style Guide for Git Commit Messages :memo:

**How you can add more value to your contribution logs:**

- Use the present tense. (Example: "Add feature" instead of "Added feature")
- Use the imperative mood. (Example: "Move item to...", instead of "Moves item to...")
- Limit the first line (also called the Subject Line) to _50 characters or less_.
- Capitalize the Subject Line.
- Separate subject from body with a blank line.
- Do not end the subject line with a period.
- Wrap the body at _72 characters_.
- Use the body to explain the _what_, _why_, _vs_, and _how_.
- Reference [Issues](https://github.com/Susmita-Dey/Moody-website/issues) and [Pull Requests](https://github.com/Susmita-Dey/Moody-website/pulls) liberally after the first line.

---
## 💥 Issues

In order to discuss changes, you are welcome to [open an issue](https://github.com/AbhishekJadhav2002/OSL-Lab-Assignments/issues/new/choose) about what you would like to contribute. Enhancements are always encouraged and appreciated.