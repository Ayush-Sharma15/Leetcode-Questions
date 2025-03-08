# Write your MySQL query statement below
select unique_id, name
from Employees as a
Left Join EmployeeUNI as b
ON a.id = b.id