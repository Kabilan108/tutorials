from pydantic import BaseModel, EmailStr, Field

# schemas are used to validate data along with serializing and deserializing data


class StudentSchema(BaseModel):
    fullname: str = Field(...)  # field is required
    email: EmailStr = Field(...)
    course_of_study: str = Field(...)
    year: int = Field(..., gt=0, le=9)
    gpa: float = Field(..., le=4.0)

    class Config:
        json_schema_extra = {
            "example": {
                "fullname": "John Doe",
                "email": "jdoe@x.edu",
                "course_of_study": "Computer Science",
                "year": 2,
                "gpa": 3.5,
            }
        }


class UpdateStudentModel(BaseModel):
    fullname: str | None
    email: EmailStr | None
    course_of_study: str | None
    year: int | None = Field(None, gt=0, le=9)
    gpa: float | None = Field(None, le=4.0)

    class Config:
        json_schema_extra = {
            "example": {
                "fullname": "John Doe",
                "email": "jdoe@x.edu",
                "course_of_study": "Computer Science",
                "year": 2,
                "gpa": 3.5,
            }
        }


def ResponseModel(data, message):
    return {"data": [data], "code": 200, "message": message}


def ErrorResponseModel(error, code, message):
    return {"error": error, "code": code, "message": message}
