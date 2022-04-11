# Write your MySQL query statement below
SELECT 
    employee_id, 
    IF (employee_id % 2 = 1 and name not like 'M%', salary, 0) AS bonus
FROM Employees
;