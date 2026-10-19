# Write your MySQL query statement below
SELECT 
    u.user_id,
    ROUND(
        AVG(
            CASE 
                WHEN u.activity_type = 'free_trial'
                THEN u.activity_duration 
            END
            ),2
    ) AS trial_avg_duration,
    ROUND(
        AVG(
            CASE 
                WHEN u.activity_type = 'paid'
                THEN u.activity_duration 
            END),2
    ) AS paid_avg_duration
FROM UserActivity u
WHERE EXISTS (
    SELECT 1 FROM UserActivity u2 WHERE u2.user_id = u.user_id AND activity_type = 'paid'
) AND EXISTS (
    SELECT 1 FROM UserActivity u2 WHERE u2.user_id = u.user_id AND activity_type =  'free_trial'
) 
GROUP BY u.user_id;
