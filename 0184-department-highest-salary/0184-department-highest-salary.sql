# Write your MySQL query statement below
SELECT d.name AS Department, e.name AS Employee, e.salary as Salary FROM Department d INNER JOIN Employee e ON e.departmentId = d.id WHERE 
e.salary = (select MAX(salary) FROM Employee e2 Where e2.departmentID = e.departmentID);