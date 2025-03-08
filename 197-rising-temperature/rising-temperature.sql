# Write your MySQL query statement below
select a.id
from Weather as a
inner join Weather as b
where datediff (a.recordDate, b.recordDate) =1 and a.temperature > b.temperature;

