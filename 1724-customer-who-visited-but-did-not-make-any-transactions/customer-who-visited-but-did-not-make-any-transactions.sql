# Write your MySQL query statement below
select customer_id, count(customer_id) as count_no_trans
from Visits as a
LEFT JOIN Transactions as b
ON a.visit_id = b.visit_id
where b.transaction_id is NULL
group by customer_id
