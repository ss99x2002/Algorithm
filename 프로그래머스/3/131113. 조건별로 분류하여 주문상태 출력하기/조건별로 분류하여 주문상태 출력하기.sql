-- 2022년 5월 1일 기준 주문 id, 제품 id, 출고일자, 출고 여부 조회
-- 출고 여부는 2022.05.01까지 출고 완료
-- 이후 날짜는 출고 대기로
-- 미정이면 출고 미정으로
-- 주문 id 기준 asc 
SELECT ORDER_ID,PRODUCT_ID,DATE_FORMAT(OUT_DATE, '%Y-%m-%d') as OUT_DATE,
CASE 
    WHEN DATE(OUT_DATE) <= '2022-05-01' THEN '출고완료'
    WHEN DATE(OUT_DATE) > '2022-05-01' THEN '출고대기'
    ELSE '출고미정'
END as '출고여부'
FROM FOOD_ORDER
ORDER BY ORDER_ID ASC