#!/bin/bash

## NOTE: Copy this backup script to the /usr/bin folder, so that it would run directly as a cron job. Also, add the job as super user by running the command:
# $ sudo crontab -e
# The crontab looks something like this:
# 0 7 * * * /usr/gitlab_backup.sh
docker exec -t gitlab_instance gitlab-backup create

# Create backup as a new zip file. This would contain everyting in the backup folder, and everything in the config folder, and mush them together in the gitlab_backup folder.
tar caf gitlab_backup.tar.gz /srv/gitlab/data/backups/* /srv/gitlab/config/gitlab.rb /srv/gitlab/config/gitlab-secrets.json

# Delete old backups, including the one just created.
rm -rf /srv/gitlab/data/backups/

# Send the backup to the destined folder.
eval `ssh-agent -s` # The next two lines are optional, in case the ssh agent is not working.
ssh-add /root/.ssh/masoud_vostro 
ssh-add /root/.ssh/yekta_dell 

rsync -az gitlab_backup.tar.gz masoud@192.168.0.10:/home/masoud/
scp gitlab_backup.tar.gz amikaniki@192.168.0.19:/E:/sirco_git_backup/

# Remove the created backup folder.
rm gitlab_backup.tar.gz

