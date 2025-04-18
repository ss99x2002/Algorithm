-- 아이스크림 성분 타입과, 성분타입에 대한 아이스크림 총 주문량
-- 총주문량 작은 순서대로 조회 asc
-- 총주문량 컬럼은 total_order
-- icetream_info
SELECT ice.ingredient_type, sum(fh.total_order) as total_order
FROM FIRST_HALF as fh join ICECREAM_INFO as ice
on fh.flavor = ice.flavor
GROUP BY ice.ingredient_type
ORDER BY total_order asc