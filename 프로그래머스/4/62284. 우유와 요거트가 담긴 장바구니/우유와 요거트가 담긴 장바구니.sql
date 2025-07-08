-- 우유와 요거트를 동시에 구입한 장바구니가 있는지 알아보기
-- 우유 요거트 동시 구입한 장바구니 아이디 조회
-- 장바구니 아이디 순 asc

WITH milk as (
    SELECT cart_id,name
    FROM CART_PRODUCTS
    WHERE name = 'Milk'
), yogurt as (
    SELECT cart_id, name
    FROM cart_products
    WHERE name = 'Yogurt'
)


SELECT cart_id
FROM milk
WHERE cart_id in (
     SELECT cart_id
    FROM cart_products
    WHERE name = 'Yogurt'
)
ORDER BY cart_id asc
