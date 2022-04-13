# Write your MySQL query statement below
SELECT
    tree.id,
    IF (ISNULL(tree.p_id),
        'Root',
        IF (tree.id IN (SELECT p_id FROM tree), 'Inner','Leaf')) Type
FROM
    tree
ORDER BY tree.id
;