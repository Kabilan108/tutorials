from fastapi import FastAPI

from .routes.student import router as StudentRouter

app = FastAPI()

app.include_router(StudentRouter, tags=["Student"], prefix="/student")

# Tags are identifiers used to group routes.
# routes with the same tag are grouped in the documentation.
@app.get("/", tags=["Root"])
async def read_root() -> dict:
    return {"message": "Welcome to your first FastAPI app."}
