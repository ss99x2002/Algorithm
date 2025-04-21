-- user_info와 online_sale 테이블에서
-- 년,월,성별 별로 상품을 구매한 회원수 집계 sql문
-- 년,월, 성별 기준 오름차순 정렬
-- 성별 없는 경우 결과 제외
SELECT YEAR(os.sales_date) as year, MONTH(os.sales_date) as month , ui.GENDER as gender, count(DISTINCT(ui.user_id)) as users
FROM user_info as ui join online_sale as os 
on ui.user_id = os.user_id
WHERE ui.GENDER IN (1,0)
GROUP BY YEAR(os.sales_date), MONTH(os.sales_date), ui.GENDER
ORDER BY year, month, gender asc