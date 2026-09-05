# Write your MySQL query statement below
select c1.category AS category1, c2.category AS category2,
    COUNT(DISTINCT p.user_id) AS customer_count     
FROM ProductInfo c1 
JOIN ProductInfo c2 ON c1.category < c2.category

JOIN ProductPurchases p ON
    p.user_id IN (
        SELECT p2.user_id FROM ProductPurchases p2 WHERE p2.product_id IN (
            SELECT c3.product_id FROM ProductInfo c3 WHERE c3.category = c1.category
        )
    ) AND 
    p.user_id IN (
        SELECT p2.user_id FROM ProductPurchases p2 WHERE p2.product_id IN (
            SELECT c3.product_id FROM ProductInfo c3 WHERE c3.category = c2.category
        )
    )
GROUP BY c1.category, c2.category
    HAVING customer_count > 2
ORDER BY customer_count DESC,c1.category ASC, c2.category ASC;
