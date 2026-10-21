# Write your MySQL query statement below
SELECT 
    ip,
    COUNT(*) AS INVALID_COUNT 
FROM logs 
WHERE 
    ip NOT LIKE '%.%.%.%' OR 
    ip LIKE '%.%.%.%.%' OR
    ip LIKE '0_%.%.%.%' OR
    ip LIKE '%.0_%.%.%' OR
    ip LIKE '%.%.0_%.%' OR
    ip LIKE '%.%.%.0_%' OR
    ip REGEXP '(^|\\.)(25[6-9]|2[6-9][0-9]|[3-9][0-9]{2}|[0-9]{4,})(\\.|$)'

GROUP BY ip
ORDER BY 
    COUNT(*) DESC,
    ip DESC;