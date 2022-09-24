# Write your MySQL query statement below
select e.employee_id from employees as e 
left join salaries as s on e.employee_id = s.employee_id where e.name is null or s.salary is null
union 
select s.employee_id from employees as e 
right join salaries as s  on e.employee_id = s.employee_id where e.name is null or s.salary is null
order by employee_id