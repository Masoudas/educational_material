The git fetch command downloads commits, files, and refs from a remote repository into your local repo. Fetching is what you do when you want to see what everybody else has been working on. It doesn’t force you to actually merge the changes into your repository. 

Git isolates fetched content from existing local content; it has absolutely no effect on your local development work. Fetched content has to be explicitly checked out using the git checkout command. This makes fetching a safe way to review commits before integrating them with your local repository.

When downloading content from a remote repo, git pull and git fetch commands are available to accomplish the task. You can consider git fetch the 'safe' version of the two commands. It will download the remote content but not update your local repo's working state, leaving your current work intact. git pull is the more aggressive alternative; it will download the remote content for the active local branch and immediately execute git merge to create a merge commit for the new remote content. If you have pending changes in progress this will cause conflicts and kick-off the merge conflict resolution flow.

How git fetch works with remote branches:
To better understand how git fetch works let us discuss how Git organizes and stores commits. Behind the scenes, in the repository's ./.git/objects directory, Git stores all commits, local and remote. Git keeps remote and local branch commits distinctly separate through the use of branch refs. The refs for local branches are stored in the ./.git/refs/heads/. Here's an example:

$ git branch
main
feature1
debug2

Remote branches are just like local branches, except they map to commits from somebody else’s repository. Remote branches are prefixed by the remote they belong to so that you don’t mix them up with local branches. Like local branches, Git also has refs for remote branches. Remote branch refs live in the ./.git/refs/remotes/ directory. The next example code snippet shows the branches you might see after fetching a remote repo conveniently named remote-repo:

$ git branch -r
# origin/main
# origin/feature1
# origin/debug2
# remote-repo/main
# remote-repo/other-feature

This output displays the local branches we had previously examined but now displays them prefixed with origin/. Additionally, we now see the remote branches prefixed with remote-repo. You can check out a remote branch just like a local one, but this puts you in a detached HEAD state (just like checking out an old commit). You can think of them as read-only branches. To view your remote branches, simply pass the -r flag to the git branch command.

You can inspect remote branches with the usual git checkout and git log commands. If you approve the changes a remote branch contains, you can merge it into a local branch with a normal git merge
Me: Here's a workflow:

$ git remote add coworkers_repo git@bitbucket.org:coworker/coworkers_repo.git
$ git fetch coworkers_repo coworkers/feature_branch 
fetching coworkers/feature_branch

$ git checkout coworkers/feature_branch # Going in a detached mode 

$ git checkout -b local_feature_branch  # Create new branch. Now everything is merged.

$ git fetch origin # Synchronization with origin
$ git checkout main
$ git merge origin/main
