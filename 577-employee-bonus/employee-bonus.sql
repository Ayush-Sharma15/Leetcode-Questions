# Write your MySQL query statement below
select a.name, b.bonus
from Employee as a
Left Join Bonus as b
ON a.empId = b.empId
where b.bonus < 1000 or b.bonus IS NULL;