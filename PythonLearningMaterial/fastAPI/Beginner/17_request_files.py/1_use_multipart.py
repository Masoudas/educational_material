"""
You can define files to be uploaded by the client using File.

File is a class that inherits directly from Form.

But remember that when you import Query, Path, File and others from fastapi, those are actually functions that return special classes.

Me: I also added a line, indicating how we can read the binary content of the file, etc. Notice the use of await, and the fact that we close the file after, because it's open.
"""

from fastapi import FastAPI, File, UploadFile

app = FastAPI()


@app.post("/files/")
async def create_file(file: bytes = File(...)):
    # open("my.ppt", "wb").write(file)
    return {"file_size": len(file)}


@app.post("/uploadfile/")
async def create_upload_file(file: UploadFile):
    content = await file.file.read()

    open(file.filename, "wb").write(content)
    file.close()

    return {"filename": file.filename}
