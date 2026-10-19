# Write your MySQL query statement below
SELECT t.id, 
    (CASE 
        WHEN t.p_id is NULL THEN 'Root' 
        WHEN t.id IN (SELECT t2.p_id FROM Tree t2) THEN 'Inner'
        ELSE 'Leaf'
    END) AS type
FROM Tree t;