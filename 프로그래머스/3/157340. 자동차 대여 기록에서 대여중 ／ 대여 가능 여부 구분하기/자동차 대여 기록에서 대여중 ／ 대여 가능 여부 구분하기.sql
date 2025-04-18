-- 코드를 입력하세요
SELECT distinct (CAR_ID),
    CASE
    WHEN CAR_ID IN (
            SELECT CAR_ID 
            FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
            WHERE '2022-10-16' BETWEEN START_DATE AND END_DATE
        )
        THEN '대여중'
        ELSE '대여 가능'
   END AS ASAVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by car_id 
ORDER BY CAR_id DESC