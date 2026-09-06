# Write your MySQL query statement below
SELECT u1.user_id as buyer_id , u1.join_date as join_date ,COUNT(o1.order_id) as orders_in_2019 FROM Users u1
LEFT JOIN Orders o1 ON u1.join_date <= o1.order_date 
AND o1.buyer_id = u1.user_id
AND YEAR(o1.order_date) = 2019
GROUP BY u1.user_id;