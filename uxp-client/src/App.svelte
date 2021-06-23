<script lang="ts">
  import { onMount } from 'svelte';
  let count: number = 0;
  onMount(() => {
    const interval = setInterval(() => count++, 1000);
    return () => {
      clearInterval(interval);
    };
  });
</script>

<div>
  <sp-heading>Welcome to eye-love-ps!</sp-heading>
  <sp-heading>This a heading</sp-heading>
  <sp-detail>Plugin has been open for <code>{count}</code> seconds.</sp-detail>
</div>

<style>
</style>
