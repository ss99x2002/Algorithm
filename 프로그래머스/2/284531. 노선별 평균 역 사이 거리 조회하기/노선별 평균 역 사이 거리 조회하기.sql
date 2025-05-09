-- SUBWAY_DISTANCE 에서
-- 노선별 노선, 총 누계 거리, 평균 역 사이 거리를
-- 노선별로 조회

-- 총 누계 거리 (존재하는 역들 사이의 거리 합) 
-- TOTAL_DISTANCE (소수점 둘째자리), AVERAGE_DISTANCE(세째자리 반올림)
SELECT ROUTE,CONCAT((ROUND(SUM(D_BETWEEN_DIST),1)) ,'km') as TOTAL_DISTANCE ,
CONCAT(ROUND((SUM(D_BETWEEN_DIST)/COUNT(NO)) ,2),'km') as AVERAGE_DISTANCE
FROM SUBWAY_DISTANCE
GROUP BY ROUTE
ORDER BY SUM(D_BETWEEN_DIST) DESC