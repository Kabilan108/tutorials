from motor.motor_asyncio import AsyncIOMotorClient
from bson.objectid import ObjectId

# database connection
MONGO_URI = "mongodb+srv://muaddib:mejqJFIa6Zzvp5uS@mkultra-01.yoqce4x.mongodb.net/"
client = AsyncIOMotorClient(MONGO_URI)
database = client["fastapi-mongo"]
student_collection = database.get_collection("students")


# helper functions
# - parse results from a database query into a dictionary
def student_helper(student) -> dict:
    return {
        "id": str(student["_id"]),
        "fullname": student["fullname"],
        "email": student["email"],
        "course_of_study": student["course_of_study"],
        "year": student["year"],
        "GPA": student["gpa"],
    }


# CRUD operations
# - use asynchronous functions to create, read, update and delete data
#   from the database using motor


# retrieve all students present in the database (READ)
async def retrieve_students():
    students = []
    async for student in student_collection.find():
        students.append(student_helper(student))
    return students


# add new student into database (CREATE)
async def add_student(student_data: dict) -> dict:
    student = await student_collection.insert_one(student_data)
    new_student = await student_collection.find_one({"_id": student.inserted_id})
    return student_helper(new_student)


# retrieve a student with a matching ID (READ)
async def retrieve_student(id: str) -> dict | None:
    student = await student_collection.find_one({"_id": ObjectId(id)})
    if student:
        return student_helper(student)


# update a student with a matching ID (UPDATE)
async def update_student(id: str, data: dict):
    # return false if an empty request body is sent
    if len(data) < 1:
        return False
    student = await student_collection.find_one({"_id": ObjectId(id)})
    if student:
        updated_student = await student_collection.update_one(
            {"_id": ObjectId(id)}, {"$set": data}
        )
        if updated_student:
            return True
        return False


# delete a student from the database (DELETE)
async def delete_student(id: str):
    student = await student_collection.find_one({"_id": ObjectId(id)})
    if student:
        await student_collection.delete_one({"_id": ObjectId(id)})
        return True
