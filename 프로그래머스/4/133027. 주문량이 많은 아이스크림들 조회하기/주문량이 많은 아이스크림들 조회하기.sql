-- 7월 아이스크림 총 주문량과 상반기의 아이스크림 총 주문량을
--  더한 값이 큰 순서대로 상위 3개의 맛을 조회하는 SQL문 
-- 상반기 FIRST_HALF
-- 7월 주문정보 JULY
SELECT fh.flavor
FROM FIRST_HALF as fh JOIN JULY as j ON fh.flavor = j.flavor
GROUP BY fh.flavor
ORDER BY sum (fh.total_order + j.total_order) DESC
LIMIT 3;
