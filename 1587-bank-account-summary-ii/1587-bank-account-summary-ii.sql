# Write your MySQL query statement below
select u.name as name, sum(t.amount) as balance from users as u, 
transactions as t 
where t.account = u.account
group by t.account 
having sum(t.amount)>10000