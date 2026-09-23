# Write your MySQL query statement below
SELECT s1.student_id as student_id, s1.subject AS subject , s1.score AS first_score, s2.score as latest_score 
FROM Scores s1 
JOIN Scores s2  
ON s1.student_id = s2.student_id
AND s1.subject = s2.subject
AND s2.score > s1.score
AND s2.exam_date > s1.exam_date
AND s2.exam_date IN (
    SELECT MAX(s3.exam_date) FROM Scores s3  
        WHERE s1.student_id = s3.student_id
        AND s1.subject = s3.subject
)
AND s1.exam_date IN (
    SELECT MIN(s3.exam_date) FROM Scores s3  
        WHERE s1.student_id = s3.student_id
        AND s1.subject = s3.subject
)
ORDER BY s1.student_id , s1.subject;