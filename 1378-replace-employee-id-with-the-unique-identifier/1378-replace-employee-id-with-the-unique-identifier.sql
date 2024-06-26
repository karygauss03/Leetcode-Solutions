# Write your MySQL query statement below
SELECT eu.unique_id, e.name FROM Employees e
LEFT JOIN EmployeeUNI eu ON eu.id = e.id