# Write your MySQL query statement below
select stu.student_id, stu.student_name,sub.subject_name, 
count(e.subject_name) as attended_exams
from Students as stu
cross join Subjects as sub #gives all combs of all cols of both tables
left join Examinations as e
on stu.student_id=e.student_id
and sub.subject_name=e.subject_name
group by stu.student_id, stu.student_name,sub.subject_name
order by stu.student_id, sub.subject_name;
