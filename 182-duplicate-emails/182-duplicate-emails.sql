# Write your MySQL query statement below

select p1.email Email from Person p1
group by p1.email
having Count(*) > 1