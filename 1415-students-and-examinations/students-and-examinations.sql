# Write your MySQL query statement below
Select Students.student_id , Students.student_name , Subjects.subject_name ,  COUNT(Examinations.subject_name) AS attended_exams
from Students Join Subjects
Left Join Examinations on Students.student_id = Examinations.student_id  and 
Subjects.subject_name = Examinations.subject_name 
GROUP BY Students.student_id, Subjects.subject_name
order by Students.student_id ,Subjects.subject_name
