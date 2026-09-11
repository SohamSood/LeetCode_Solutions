SELECT d.name as Department, e.name as Employee, e.salary as Salary
FROM Department d
JOIN Employee e
    ON e.departmentId = d.id
WHERE 3 > (
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee e2
    WHERE e2.departmentId = e.departmentId
    AND e2.salary > e.salary
)