# Write your MySQL query statement below
select e1.name
from Employee as e1
inner join Employee as e2
on e1.id=e2.managerId
group by e1.id, e1.name #group by id as well, as names can be same but id is primary
having count(e2.managerId) >= 5;