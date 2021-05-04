/**
 * We can add resource files directly to the program (which is shipped with the binary) using a qrc file, which
 * is built using add new. For example, we might want to have one qrc for our icons, one for our images, media,
 * etc. 
 * 
 * Me: I think when we put a : before a path, it means read it from our resources, otherwise, we read it from a
 * path. For example:
 
 QPixmap log_resource{":/myLogo.svg"};  // Read from the resource file.
 QPixmap log_from_disk{"/home/masoudas/project/myLogo.svg"}

 */