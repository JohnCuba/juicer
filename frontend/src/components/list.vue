<script lang="ts" setup generic="T extends { slot: string; key: string }">
import { type PropType } from 'vue'

defineProps({
  items: {
    type: Array as PropType<T[]>,
    default: null,
  },
})

const emit = defineEmits<{
  click: [value: T['key']]
}>()

const handleClick = (itemKey: T['key']) => {
  emit('click', itemKey)
}
</script>

<template>
  <ul class="root">
    <li v-for="item in items" :key="item.key" class="entity" @click="handleClick(item.key)">
      <slot :name="item.slot" v-bind="item" />
    </li>
  </ul>
</template>

<style lang="css" scoped>
.root {
  width: 100%;
  list-style: none;
  padding: 1rem 0;
}

.entity:nth-child(1n):not(:last-child) {
  border-bottom: 0.1px solid var(--palette-contrast);
}

.entity {
  display: block;
  width: 100%;
  border: none;
  text-align: start;
  color: var(--palette-contrast);
  text-decoration: none;
  font-size: 1.2em;
  cursor: pointer;
  transition: all 0.2s ease-in-out;
}

.entity:hover {
  backdrop-filter: contrast(85%);
}
</style>
