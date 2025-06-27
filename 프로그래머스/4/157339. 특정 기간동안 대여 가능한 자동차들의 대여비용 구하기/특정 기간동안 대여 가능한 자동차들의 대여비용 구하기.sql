-- 자동차 종류 '세단' or 'SUV'인 자동차중
-- 2022-11-1~2022-11-30까지 대여 가능하고, 
-- 30일간 대여 금액이 50만원 이상 ~ 200만원 미만 자동차

-- 자동차 id, 종류, 대여금액 (fee) 출력 
-- 대여금액 desc, 자동차 종류 asc, 자동차 id desc

WITH avail_car AS (
  SELECT
    c.car_id,
    c.car_type,
    c.daily_fee
  FROM CAR_RENTAL_COMPANY_CAR AS c
  WHERE c.car_type IN ('세단','SUV')
    -- 이 기간과 겹치는 이력이 하나도 없는 차만
    AND NOT EXISTS (
      SELECT 1
      FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY AS h
      WHERE h.car_id = c.car_id
        -- 겹친다는 것은 시작일이 11/30 이전이면서 종료일이 11/1 이후인 경우
        AND h.start_date <= '2022-11-30'
        AND h.end_date   >= '2022-11-01'
    )
)

 SELECT distinct(ac.car_id) as car_id,
 ac.car_type as car_type,
 TRUNCATE((ac.daily_fee * 30) * (1- (cp.discount_rate *1.0 / 100)),0) as fee
 FROM avail_car as ac JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN as cp
 ON ac.car_type = cp.car_type
 WHERE cp.duration_type = '30일 이상' AND 
 ((ac.daily_fee * 30) * (1- (cp.discount_rate *1.0 / 100))) >= 500000  AND  
 ((ac.daily_fee * 30) * (1- (cp.discount_rate *1.0 / 100))) < 2000000
 ORDER BY fee desc, car_type asc, car_id desc
 
 

 
 
 
 
 
 
 