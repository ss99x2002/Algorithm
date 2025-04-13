-- 대여 시작일을 기준으로 2022, 08부터 10까지 대여횟수 5회 이상인 자동차
-- 월별 자동차 id별 총 대여횟수 (recods) 출력
-- 월 기준 오름차순, 자동차 id 내림차순
-- 총대여횟수 0인경우 결과 제외
SELECT MONTH(start_date) as month, car_id, count(*) as records
FROM car_rental_company_rental_history
WHERE start_date between '2022-08-01' and '2022-10-31'
and car_id in (
    select car_id
    from car_rental_company_rental_history
    where start_date between '2022-08-01' and '2022-10-31'
    group by car_id
    having count(*) >= 5
)
GROUP BY MONTH(start_date), car_id
ORDER BY month asc, car_id desc