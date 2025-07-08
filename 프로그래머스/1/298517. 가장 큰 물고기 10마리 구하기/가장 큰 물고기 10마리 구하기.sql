-- 가장 큰 물고기 10마리 id와 길이 출력
-- 길이 기준 내림차순, 길이 같으면 id 오름차순

with max_fish as (SELECT ID, LENGTH, RANK() OVER (
ORDER BY LENGTH DESC
) as ranks
FROM FISH_INFO
                 )

SELECT id, length
FROM max_fish
WHERE ranks <= 10

