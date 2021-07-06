<script lang="ts">
  import { onMount } from 'svelte';
  let count: number = 0;
  onMount(() => {
    const interval = setInterval(() => count++, 1000);
    return () => {
      clearInterval(interval);
    };
  });

  const log = () => {
    console.log('click!');
  }
</script>

<div class="container">
  <div class="row">
    <sp-heading>Disco-Ps</sp-heading>
  </div>
  <div class="row">
    <sp-textfield placeholder="Send a message...">
      <sp-label is-required="true" slot="label">Message</sp-label>
    </sp-textfield>
  </div>
  <div class="row">
    <sp-button variant="cta" on:click={log}>Send</sp-button>
  </div>
  <div class="row">
    <sp-detail>Plugin has been open for <code>{count}</code> seconds.</sp-detail>
  </div>
</div>

<style>
  .container {
    display: flex;
    flex-direction: column;
    align-items: center;
    height: 100%;
    padding: 0.5em;
  }

  .row > * {
    margin: 6px 8px;
  }
</style>
