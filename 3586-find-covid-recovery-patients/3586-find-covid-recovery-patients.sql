# Write your MySQL query statement below
SELECT DISTINCT(p.patient_id), p.patient_name, p.age , DATEDIFF(c2.test_date,c.test_date) as recovery_time FROM patients p 
JOIN covid_tests c ON p.patient_id = c.patient_id AND c.result = 'Positive'
JOIN covid_tests c2 ON p.patient_id = c2.patient_id 
AND c2.result  = 'Negative'
AND c2.test_date > c.test_date
WHERE c.test_date = (
    SELECT MIN(c3.test_date) FROM covid_tests c3 
    WHERE p.patient_id = c3.patient_id
    AND c3.result = 'Positive' 
)
AND 
c2.test_date = (
    SELECT MIN(c4.test_date) FROM covid_tests c4 
    WHERE p.patient_id = c4.patient_id
    AND c4.result = 'Negative' 
    AND c4.test_date > c.test_date
)
ORDER BY recovery_time,p.patient_name ASC;
