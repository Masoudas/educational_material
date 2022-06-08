"""
Using UploadFile has several advantages over bytes:

    -   You don't have to use File() in the default value of the parameter.
    -   It uses a "spooled" file:
    -   A file stored in memory up to a maximum size limit, and after passing this limit it will be stored in disk. This means that it will work well for large files like images, videos, large binaries, etc. without consuming all the memory.
    -   You can get metadata from the uploaded file.
    -   It has a file-like async interface.
    -   It exposes an actual Python SpooledTemporaryFile object that you can pass directly to other libraries that expect a file-like object.

"""
