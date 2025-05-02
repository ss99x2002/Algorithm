-- 아이템 희귀도가 'RARE'인 아이템들의 모든
-- 다음 업그레이드 아이템의
-- 아이템 ID, 아이템명, 아이템 희귀도 출력
-- 아이템 ID 기준 DESC 

SELECT i.ITEM_ID, i.ITEM_NAME, i.RARITY 
FROM ITEM_INFO as i JOIN ITEM_TREE as t
ON i.ITEM_ID = t.ITEM_ID
WHERE t.PARENT_ITEM_ID IN (
        SELECT ITEM_ID
        FROM ITEM_INFO
        WHERE RARITY = 'RARE'
    )
ORDER BY i.ITEM_ID DESC