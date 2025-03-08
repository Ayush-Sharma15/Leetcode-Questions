# Write your MySQL query statement below
select product_name, year, price
from sales as a
left join Product as b
ON a.product_id = b.product_id