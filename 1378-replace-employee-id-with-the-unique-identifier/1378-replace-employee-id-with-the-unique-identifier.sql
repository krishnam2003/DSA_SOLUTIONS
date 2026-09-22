# Write your MySQL query statement below

select name, unique_id
from employees e
left join employeeuni eu on e.id = eu.id;