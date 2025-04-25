-- FISH_INFO에서 평균 길이가 33cm이상인 물고기들
-- 종류별로 분류
-- 잡은 수, 최대 길이, 물고기 종류 출력
-- 물고기 종류 ASC, 10cm이하는 10cm로 취급해서 평균길이
-- ----- 이 조건 처리 방법 -> 
-- 평균은 AVG 활용하고, 그 안에서 lenght가 10이하일때를 처리함. 
SELECT COUNT(*) as FISH_COUNT, 
MAX(LENGTH) as MAX_LENGTH,
FISH_TYPE 
FROM FISH_INFO
GROUP BY FISH_TYPE
HAVING  ROUND(AVG(CASE 
            WHEN LENGTH IS NULL THEN 10
            ELSE LENGTH
           END)) >= 33
ORDER BY FISH_TYPE ASC