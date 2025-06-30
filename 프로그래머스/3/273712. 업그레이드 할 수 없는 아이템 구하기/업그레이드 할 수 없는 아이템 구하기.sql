-- 더이상 업그레이드 할 수 없는 아이템의
-- 아이템 id, 아이템 명, 희귀도 출력
-- 아이템 Id 기준 DESC

SELECT ii.item_id, ii.item_name, ii.rarity
FROM ITEM_INFO as ii LEFT JOIN ITEM_TREE as it
ON ii.item_id = it.parent_item_id
WHERE it.parent_item_id IS NULL
ORDER BY ii.item_id DESC