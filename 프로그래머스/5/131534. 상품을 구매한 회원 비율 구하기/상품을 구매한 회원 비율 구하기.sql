-- 2021년에 가입한 전체 회원들 중
-- 상품을 구매한 회원수, 구매한 수/ 2021년 가입 수 를 년월로 출력. 

WITH joined as (
    SELECT COUNT(distinct(ui.user_id)) as cnt
    FROM user_info as ui
    WHERE ui.joined BETWEEN '2021-01-01' AND '2021-12-31'
)

SELECT  YEAR(os.sales_date) as YEAR, 
MONTH(os.sales_date) as MONTH, 
COUNT(distinct(os.user_id)) as PURCHASED_USERS, 
round(COUNT(distinct(os.user_id)) /  (joined.cnt*1.0),1) as PUCHASED_RATIO
FROM user_info as ui JOIN ONLINE_SALE as os
ON ui.user_id = os.user_id, joined
WHERE ui.joined BETWEEN '2021-01-01' AND '2021-12-31'
GROUP BY YEAR(os.sales_date), MONTH(os.sales_date)
ORDER BY YEAR(os.sales_date), MONTH(os.sales_date) ASC






