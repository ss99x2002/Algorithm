-- 코드를 입력하세요
-- 자동차 종류가 세단 또는 SUV인 자동차중
-- 2022년 11월 1일부터 2022년 11월 30일까지 대여 가능하고
-- 30일간 대여 금액이 50만원 이상, 200만원 미만인 자동차에 대해
-- 자동차 id, 자동차 종류, 대여금액 (fee) 리스트 출력하는 sql문
-- 대여금액을 기준으로 내림차순 정렬, 대여금액 같은 경우 자동차 종류 기준 오름차순 정렬
-- 자동차 종류까지 같으면 자동차 id기준 내림차준 정렬
SELECT c.car_id, c.car_type, FLOOR((c.daily_fee * 30) * (1-d.discount_rate/100)) as fee
FROM
 car_rental_company_car as c
 join car_rental_company_discount_plan as d 
 on c.car_type = d.car_type
WHERE
    c.car_type IN ('세단', 'SUV')
    AND d.duration_type = '30일 이상'
    AND c.car_id NOT IN (
    SELECT car_id
    FROM car_rental_company_rental_history
    WHERE NOT (end_date < '2022-11-01' OR start_date > '2022-11-30')
    )
    AND FLOOR((c.daily_fee * 30) * (1-d.discount_rate/100)) BETWEEN 500000 AND 1999999
ORDER BY
    fee DESC,
    car_type ASC,
    car_id DESC;

