# Write your MySQL query statement below
select s.user_id, ifnull(round(sum(c.action='confirmed')/count(*),2),0.00) as confirmation_rate
from Signups as s
left join Confirmations as c
on s.user_id=c.user_id
group by s.user_id; #baar baar same userid ka row nhi chaiye, so group by it 