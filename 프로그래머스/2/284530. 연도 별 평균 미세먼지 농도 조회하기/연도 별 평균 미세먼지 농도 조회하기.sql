-- AIR_POLLUTION 테이블에서
-- 수원 지역의 연도별 평균 미세먼지 오염도와
-- 평균 초미세먼지 오염도를 조회하느 SQL 
-- PM10 -> 미세
-- PM2.5 -> 초미세
-- 소수 셋째자리에서 반올림 -> 2째짜리까지.
-- 연도기준 오름차순
SELECT YEAR(AP.YM) as 'YEAR', ROUND((SUM(AP.PM_VAL1) / COUNT(AP.PM_VAL1)),2) as 'PM10', ROUND((SUM(AP.PM_VAL2)/ COUNT(AP.PM_VAL2)),2) as 'PM2.5'
FROM (
    SELECT YM, PM_VAL1, PM_VAL2
    FROM AIR_POLLUTION
    WHERE LOCATION1 = '경기도' AND LOCATION2 ='수원'
) as AP
GROUP BY YEAR(AP.YM)
ORDER BY YEAR(AP.YM) ASC