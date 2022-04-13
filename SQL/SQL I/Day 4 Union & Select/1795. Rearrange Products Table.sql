# Write your MySQL query statement below
SELECT * FROM
(
    SELECT product_id, 'store1' AS store, store1 AS price 
    FROM Products p1
    UNION
    SELECT product_id, 'store2' AS store, store2 AS price
    FROM Products p2
    UNION
    SELECT product_id, 'store3' AS store, store3 AS price
    FROM Products p3
) total
WHERE price IS NOT NULL
;