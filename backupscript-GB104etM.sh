#Set the date and name for the backup files
date=`date '+%F-%H-%M'`
backupname="kandc.backup.$date.tar.gz"

#Dump the mysql database

mysqldump -h $db_host -u $db_user --password="$db_password" $db_name > $webroot/db_backup.sql

#Backup Site
tar -czpvf $webroot/sitebackup.tar.gz $webroot/web/content/

#Compress DB and Site backup into one file
tar --exclude 'sitebackup' --remove-files -czpvf $webroot/$backupname $webroot/sitebackup.tar.gz $webroot/db_backup.sql

#Upload your files to cloud files.
#First argument is the location of the backup file, second argument is the name to be used when uploaded
php $webroot/cloudfiles_backup.php $webroot/$backupname $backupname

#After your backup has been uploaded, remove the tar ball from the filesystem.
rm $webroot/$backupname